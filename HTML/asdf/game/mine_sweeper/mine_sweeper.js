document.addEventListener('DOMContentLoaded', () => {
    var grid = document.querySelector('.mine_sweeper .grid');
    var flagsLeft = document.querySelector('.mine_sweeper #flags-left');
    var result = document.querySelector('.mine_sweeper #result');
    let flags = 0;
    var squares = [];
    var isGameOver = false;
    var isStart = false;
    document.getElementById("size_of_minesweeper").addEventListener('submit', run, false);
    function run(e){
        e.preventDefault();
        var width = Number(document.querySelector('.mine_sweeper #size_of_minesweeper #width').value);
        var height = Number(document.querySelector('.mine_sweeper #size_of_minesweeper #height').value);
        var bombAmount = Number(document.querySelector('.mine_sweeper #size_of_minesweeper #bombAmount').value);
        if(isStart){
            child_square = grid.querySelectorAll('div');
            for(var i = 0; i < child_square.length; i++){
                grid.removeChild(child_square[i]);
            }
            isStart = false;
            isGameOver = false;
            result.innerHTML = '';
            flags = 0;
            squares = [];
            return run(e);
        }
        if(bombAmount >= (width*height)) return (alert(`폭탄의 양은 판의 넓이(=${height*width})보다 크거나 같을 수 없습니다.`))
        isStart = true;
        grid.setAttribute('style', `width: ${40*width}px; height: ${40*height}px;`)
        //create Board
        function createBoard() {
            flagsLeft.innerHTML = bombAmount;
            //get shuffled game array with random bombs
            var bombsArray = Array(bombAmount).fill('bomb');
            var emptyArray = Array(width*height - bombAmount).fill('valid');
            var gameArray = emptyArray.concat(bombsArray);
            var shuffledArray = gameArray.sort(() => Math.random() -0.5);

            for(var i = 0; i < width*height; i++){
                let square = document.createElement('div');
                square.setAttribute('id', i);
                square.classList.add(shuffledArray[i])
                grid.appendChild(square);
                squares.push(square);

                //normal click
                square.addEventListener('click', function(e) {
                    if(!square.classList.contains('checked')) click(square);
                    else{
                        var currentId = square.id;
                        checkCheckedSquare(square,currentId);
                    }
                })

                //cntrl and left click
                square.oncontextmenu = function(e) {
                    e.preventDefault();
                    addFlag(square);
                }
            }

            //add numbers
            for(var i = 0; i < squares.length; i++){
                let total = 0;
                var isLeftEdge = i % width === 0;
                var isRightEdge = i % width === width - 1;
                
                if (squares[i].classList.contains('valid')){
                    if (i > 0 && !isLeftEdge && squares[i - 1].classList.contains('bomb'))total ++
                    if (i > width-1 && !isRightEdge && squares[i + 1 -width].classList.contains('bomb')) total ++
                    if (i > width-1 && squares[i-width].classList.contains('bomb')) total ++;
                    if (i > width && !isLeftEdge && squares[i - 1 -width].classList.contains('bomb')) total ++;
                    if (i < width*height-1 && !isRightEdge && squares[i + 1].classList.contains('bomb')) total ++;
                    if (i < width*height-width && !isLeftEdge && squares[i - 1 +width].classList.contains('bomb')) total ++;
                    if (i < width*height-width-1 && !isRightEdge && squares[i + 1 +width].classList.contains('bomb')) total ++;
                    if (i < width*height-width && squares[i +width].classList.contains('bomb')) total ++;
                    squares[i].setAttribute('data', total);         
                    console.log(squares[i].getAttribute('data'));
                }
            }
        }
        createBoard()

        //add Flag with right click
        function addFlag(square) {
            if(isGameOver) return;
            if (!square.classList.contains('checked')){
                if((flags < bombAmount)) {
                    if(!square.classList.contains('flag')) {
                        square.classList.add('flag');
                        square.innerHTML = '🚩';
                        flags ++;
                        flagsLeft.innerHTML = bombAmount - flags;
                        checkForWin();
                    } else {
                        square.classList.remove('flag');
                        square.innerHTML = '';
                        flags --;
                        flagsLeft.innerHTML = bombAmount - flags;
                    }
                } else if((flags === bombAmount) && (square.classList.contains('flag'))){
                    square.classList.remove('flag');
                    square.innerHTML = '';
                    flags --;
                    flagsLeft.innerHTML = bombAmount - flags;
                }
            }
        }

        //click on square actions
        function click(square) {
            var currentId = square.id
            if (isGameOver) return;
            if (square.classList.contains('flag') || square.classList.contains('checked')) return;
            if (square.classList.contains('bomb')) gameOver(square)
            else {
                let total = square.getAttribute('data');
                if (total !=0) {
                    square.classList.add('checked');
                    if (total == 1) square.classList.add('one')
                    if (total == 2) square.classList.add('two')
                    if (total == 3) square.classList.add('three')
                    if (total == 4) square.classList.add('four')
                    if (total == 5) square.classList.add('five')
                    if (total == 6) square.classList.add('six')
                    if (total == 7) square.classList.add('seven')
                    if (total == 8) square.classList.add('eight')
                    square.innerHTML = total;
                    checkForWin();
                    return;
                }
                checkSquare(square, currentId);
            }
            square.classList.add('checked');
        }

        //check neighboring squares once square is clicked
        function checkSquare(square, currentId) {
            var isLeftEdge = (currentId % width === 0)
            var isRightEdge = (currentId % width === width -1)

            setTimeout(() => {
                if (currentId > 0 && !isLeftEdge) {
                    var newId = squares[parseInt(currentId) -1].id;
                    var newSquare = document.getElementById(newId);
                    click(newSquare);
                }
                if (currentId > width-1 && !isRightEdge) {
                    var newId = squares[parseInt(currentId) +1 -width].id;
                    var newSquare = document.getElementById(newId);
                    click(newSquare);
                }
                if (currentId > width-1) {
                    var newId = squares[parseInt(currentId) -width].id;
                    var newSquare = document.getElementById(newId);
                    click(newSquare);
                }
                if (currentId > width && !isLeftEdge) {
                    var newId = squares[parseInt(currentId) -1 -width].id;
                    var newSquare = document.getElementById(newId);
                    click(newSquare);
                }
                if (currentId < width*height-1 && !isRightEdge) {
                    var newId = squares[parseInt(currentId) +1].id;
                    var newSquare = document.getElementById(newId);
                    click(newSquare);
                }
                if (currentId < width*height-width && !isLeftEdge) {
                    var newId = squares[parseInt(currentId) -1 +width].id;
                    var newSquare = document.getElementById(newId);
                    click(newSquare);
                }
                if (currentId < width*height-width-1 && !isRightEdge) {
                    var newId = squares[parseInt(currentId) +1 +width].id;
                    var newSquare = document.getElementById(newId);
                    click(newSquare);
                }
                if (currentId < width*height-width) {
                    var newId = squares[parseInt(currentId) +width].id;
                    var newSquare = document.getElementById(newId);
                    click(newSquare);
                }
                console.log(newSquare);
            }, 10)
        }

        // When you click checked square
        function checkCheckedSquare(square, currentId){
            var isLeftEdge = (currentId % width === 0)
            var isRightEdge = (currentId % width === width -1)
            var totalFlag = 0
            if (currentId > 0 && !isLeftEdge) {
                var newId = squares[parseInt(currentId) -1].id;
                var newSquare = document.getElementById(newId);
                if(newSquare.classList.contains('flag')){totalFlag ++;}
            }
            if (currentId > width-1 && !isRightEdge) {
                var newId = squares[parseInt(currentId) +1 -width].id;
                var newSquare = document.getElementById(newId);
                if(newSquare.classList.contains('flag')){totalFlag ++;}
            }
            if (currentId > width-1) {
                var newId = squares[parseInt(currentId) -width].id;
                var newSquare = document.getElementById(newId);
                if(newSquare.classList.contains('flag')){totalFlag ++;}
            }
            if (currentId > width && !isLeftEdge) {
                var newId = squares[parseInt(currentId) -1 -width].id;
                var newSquare = document.getElementById(newId);
                if(newSquare.classList.contains('flag')){totalFlag ++;}
            }
            if (currentId < width*height-1 && !isRightEdge) {
                var newId = squares[parseInt(currentId) +1].id;
                var newSquare = document.getElementById(newId);
                if(newSquare.classList.contains('flag')){totalFlag ++;}
            }
            if (currentId < width*height-width && !isLeftEdge) {
                var newId = squares[parseInt(currentId) -1 +width].id;
                var newSquare = document.getElementById(newId);
                if(newSquare.classList.contains('flag')){totalFlag ++;}
            }
            if (currentId < width*height-width-1 && !isRightEdge) {
                var newId = squares[parseInt(currentId) +1 +width].id;
                var newSquare = document.getElementById(newId);
                if(newSquare.classList.contains('flag')){totalFlag ++;}
            }
            if (currentId < width*height-width) {
                var newId = squares[parseInt(currentId) +width].id;
                var newSquare = document.getElementById(newId);
                if(newSquare.classList.contains('flag')){totalFlag ++;}
            }
        
            if(square.getAttribute('data') == totalFlag){
                checkSquare(square, currentId);
            }
        }

        //game over
        function gameOver(square) {
            result.innerHTML = 'BOOM! Game Over!'
            isGameOver = true;

            //show ALL the bombs
            squares.forEach(square => {
                if(square.classList.contains('bomb')) {
                    square.innerHTML = '💣';
                    square.classList.remove('bomb');
                    square.classList.add('checked');
                }
            })
        }

        //check for win
        function checkForWin() {
            let matches = 0;
            let correct_check = 0;
            for (var i = 0; i < squares.length; i++) {
                if(squares[i].classList.contains('flag') && squares[i].classList.contains('bomb')) matches ++;
                if(squares[i].classList.contains('checked')&&!(squares[i].classList.contains('bomb'))) correct_check ++;
                if (matches === bombAmount && correct_check === (width*height-bombAmount)) {
                    result.innerHTML = 'YOU WIN!';
                    isGameOver = true;
                }
            }
            console.log(`correct_check: ${correct_check}`);
            console.log(`matches: ${matches}`);
            console.log(isGameOver);
        }
    }
})