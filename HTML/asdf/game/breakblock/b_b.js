canva = document.getElementById("bb");
ctxs = canva.getContext("2d")
ballRadius = 10;
paddleHeight = 10;
paddleWidth = 75;
paddleX = (canva.width-paddleWidth)/2;
rightPressed = false;
leftPressed = false;
x = canva.width/2;
y = canva.height-30;
dx = 2;
dy = -2;
brickRowCount = 3;
brickColumnCount = 5;
brickWidth = 75;
brickHeight = 20;
brickPadding = 10;
brickOffsetTop = 30;
brickOffsetLeft = 30;
bb_score = 0;
lives = 3;
bb_playing = false;

//ctxs.beginPath(); 색칠놀이 시작
//직사각형: ctxs.rect(캔버스 좌측에서 떨어진 거리, 캔버스 상단에서 떨어진 거리, 너비, 높이);
//원: ctxs.arc(원의 중심 X좌표, 원의 중심 Y좌표, 반지름, 원 그리기 시작하는 각도(라디안), 끝나는 각도(라디안), 그리는 방향(false = 시계방향_));
//ctxs.fillStyle = 도형 색깔 채우기
//ctxs.fill();
//ctxs.strokeStyle = 도형 외곽선 색깔
//ctxs.stroke();
//ctxs.closePath(); 색칠놀이 끝

//
//setInterval(함수 이름, 밀리초) -> 밀리초마다 함수를 실행함
//requestAnimationFrame(함수명) 이게 Interval 보다 좋음

//벽돌 초기화
bricks = [];
for(c=0; c<brickColumnCount; c++){
    bricks[c] = [];
    for(r=0; r<brickRowCount; r++){
        bricks[c][r] = { x: 0, y: 0, status: 1};
    }
}

//키다운 / 키업 / 마우스무브 이벤트
document.addEventListener("keydown", keyDownHandler, false);
document.addEventListener("keyup", keyUpHandler, false);
document.addEventListener("mousemove", mouseMoveHandler, false);
function keyDownHandler(e) {
    switch(e.keyCode) {
        case 39:
            rightPressed = true;
            break;
        case 37:
            leftPressed = true;
            break;
        case 35:
            if(bb_playing == false){
                bb_game();
                bb_playing = true;
            }
            break;
    }
}

function keyUpHandler(e) {
    switch(e.keyCode) {
        case 39:
            rightPressed = false;
            break;
        case 37:
            leftPressed = false;
            break;
    }
}
function mouseMoveHandler(e){
    relativeX = e.clientX - canva.offsetLeft;
    if(relativeX > 0 && relativeX < canva.width) {
        paddleX = relativeX - paddleWidth/2;
    }
}
//벽돌과의 충돌 감지
function collisionDetection(){
    for(c=0; c<brickColumnCount; c++){
        for(r=0; r<brickRowCount; r++){
            b = bricks[c][r];
            if(b.status == 1){
                if(x > b.x && x < b.x+brickWidth && y > b.y && y < b.y+brickHeight){
                    dy = -dy;
                    b.status = 0;
                    bb_score++;
                    if(bb_score == brickRowCount*brickColumnCount) {
                        alert("YOU WIN, CONGRATULATIONS!");
                        document.location.reload();
                    }
                }
            }
        }
    }
}
//점수판 그리기
function drawScore() {
    ctxs.font = "16px Arial";
    ctxs.fillStyle = "#0095DD";
    ctxs.fillText("Score: "+bb_score, 8, 20);
}
//목숨 그리기?
function drawLives() {
    ctxs.font = "16px Arial";
    ctxs.fillStyle = "#0095DD";
    ctxs.fillText("Lives: " + lives, canva.width-65, 20);
}
//공 그리기
function drawBall(){
    ctxs.beginPath();
    ctxs.arc(x, y, ballRadius, 0, Math.PI*2);
    ctxs.fillStyle = "#0095DD";
    ctxs.fill();
    ctxs.closePath();
}
//paddle 그리기
function drawPaddle(){
    ctxs.beginPath();
    ctxs.rect(paddleX, canva.height-paddleHeight, paddleWidth, paddleHeight);
    ctxs.fillStyle = "#0095DD";
    ctxs.fill();
    ctxs.closePath();
}
//벽돌 그리기
function drawBricks(){
    for(c=0; c<brickColumnCount; c++){
        for(r=0; r<brickRowCount; r++){
            if(bricks[c][r].status == 1) {
                brickX = (c*(brickWidth+brickPadding))+brickOffsetLeft;
                brickY = (r*(brickHeight+brickPadding))+brickOffsetTop;
                bricks[c][r].x = brickX;
                bricks[c][r].y = brickY;
                ctxs.beginPath();
                ctxs.rect(brickX, brickY, brickWidth, brickHeight);
                ctxs.fillStyle = "#0095DD"
                ctxs.fill();
                ctxs.closePath();
            }
        }
    }
}

function bb_game(){
    ctxs.clearRect(0, 0, canva.width, canva.height);
    //그림 지우기
    drawBricks();
    drawBall();
    drawPaddle();
    drawScore();
    drawLives();
    collisionDetection();

    //공 튕기기
    if(x + dx > canva.width-ballRadius || x + dx < ballRadius) dx = -dx;
    if(y + dy < ballRadius) dy = -dy;
    //아래방향으로 가면 GAME OVER
    else if(y + dy > canva.height-ballRadius) {
        if(x > paddleX && x < paddleX + paddleWidth) dy = -dy;
        else{
            lives--;
            if(!lives) {
                alert("GAME OVER");
                document.location.reload();
            }
            else {
                x = canva.width/2;
                y = canva.height-30;
                dx = 2;
                dy = -2;
                paddleX = (canva.width-paddleWidth)/2;
            }
        }
    }

    //좌 우 버튼 누르면 paddle 움직이기
    if(rightPressed && paddleX < canva.width-paddleWidth) paddleX += 7;
    else if(leftPressed && paddleX > 0) paddleX -= 7;

    x += dx;
    y += dy;
    requestAnimationFrame(bb_game);
}
