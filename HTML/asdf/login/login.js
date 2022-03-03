var log_in = document.getElementById("login");
var regist = document.getElementById("register");
var loginBtn = document.getElementById("login_btn");

function register(){
    log_in.style.left = "-400px";
    regist.style.left = "50px";
    loginBtn.style.left = "110px";
}

function login(){
    log_in.style.left = "50px";
    regist.style.left = "450px";
    loginBtn.style.left = "0px";
}