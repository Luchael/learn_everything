window.onload=function() {
    canv=document.getElementById("gc");
    ctx=canv.getContext("2d");
    document.addEventListener("keydown", keyPush);
    s_playing = false;
}

px=py=10;
gs=20;
tc=30;
ax=ay=15;
xv=yv=0;
trail=[];
tail=5;
highscore = 0;
s_score = 0;

function drawingScore() {
    ctx.font = "16px Arial";
    ctx.fillStyle = "#0095DD";
    ctx.fillText("Score: "+s_score, 8, 20);
    ctx.fillText("HighScore: "+highscore, 8, 40)
}

function s_game(){
    px+=xv;
    py+=yv;
    if(px<0){
        px= tc-1;
    }
    if(px>tc-1){
        px= 0;
    }
    if(py<0){
        py= tc-1;
    }
    if(py>tc-1){
        py= 0;
    }
    ctx.fillStyle="black";
    ctx.fillRect(0,0,canv.width,canv.height);
    drawingScore();
    for(var i=0;i<trail.length;i++){
        if(i%35<5)ctx.fillStyle="lime";
        else if(i%35<10)ctx.fillStyle="orange";
        else if(i%35<15)ctx.fillStyle="yellow";
        else if(i%35<20)ctx.fillStyle="blue";
        else if(i%35<25)ctx.fillStyle="black";
        else if(i%35<30)ctx.fillStyle="white";
        else if(i%35<35)ctx.fillStyle="red";
        ctx.fillRect(trail[i].x*gs, trail[i].y*gs, gs-2, gs-2);
        if(trail[i].x==px && trail[i].y==py){
            tail = 5;
            px=py=10;
            if(s_score > highscore)highscore = s_score;
            s_score = 0;
        }
    }
    trail.push({x:px, y:py});
    while(trail.length>tail){
        trail.shift();
    }

    if(ax==px && ay==py){
        s_score++;
        tail++;
        ax=Math.floor(Math.random()*tc);
        ay=Math.floor(Math.random()*tc);
    }

    ctx.fillStyle="red";
    ctx.fillRect(ax*gs, ay*gs, gs-2, gs-2);
}
function keyPush(evt){
    switch(evt.keyCode) {
        case 37:
            if(xv!=1){xv=-1;yv=0;}
        break;
        case 38:
            if(yv!=1){xv=0;yv=-1;}
        break;
        case 39:
            if(xv!=-1){xv=1;yv=0;}
        break;
        case 40:
            if(yv!=-1){xv=0;yv=1;}
        break;
        case 36:
            if(s_playing == false){
                setInterval(s_game, 1000/15);
                s_playing = true;
            }
        break;
    }
}