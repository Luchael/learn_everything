//다음부터는 여러 요소 한번에 할 때 forEach 사용
const toggleBtn = document.querySelector('.navbar_toogleBtn');
const menu = document.querySelector('.navbar_menu');
const icons = document.querySelector('.navbar_icons');
const homework = document.querySelector('.homework');
const HomeworkMenu = document.querySelector('.homework_menu');
const HomeWorkMenu_a = document.querySelector('.homework_subject_a');
const homeworks_a = document.querySelector('.homework_subject_a ol');
const HomeWorkMenu_b = document.querySelector('.homework_subject_b');
const homeworks_b = document.querySelector('.homework_subject_b ol');
const schedulebtn = document.querySelector('.시간표');
const home_workbtn = document.querySelector('.과제');
const needs = document.querySelector('.필요한것');
const asdfasdf = document.querySelector('.진도');
const songs = document.querySelector('.노래');
const schedule = document.querySelector('.schedule_main');
const home_work = document.querySelector('.homework_main');
const table = document.querySelector('.table');
const checkbox = document.getElementById('checkbox');
const snake = document.querySelector('.뱀');
const b_b = document.querySelector('.벽돌');

checkbox.addEventListener('change', () =>{
	//change the theme of the website
	document.body.classList.toggle('dark');
	table.classList.toggle('dark');
	document.querySelector('.label').classList.toggle('dark');
	document.querySelector('.navbar').classList.toggle('dark');
	document.querySelector('.a').classList.toggle('dark');
	document.querySelector('.fa-cat').classList.toggle('dark');
	schedulebtn.classList.toggle('dark');
	home_workbtn.classList.toggle('dark');
	document.querySelector('.fa-twitter-square').classList.toggle('dark');
	document.querySelector('.fa-facebook-square').classList.toggle('dark');
	document.querySelector('.fa-instagram-square').classList.toggle('dark');
	document.querySelector('.fa-github-square').classList.toggle('dark');
	needs.classList.toggle('dark');
	document.querySelector('.needs_subject_a ol ._a').classList.toggle('dark');
	document.querySelector('.needs_subject_b ol ._a').classList.toggle('dark');
	document.querySelector('.needs_subject_b ol ._b').classList.toggle('dark');
	cursor.classList.toggle('dark');
	cursor_a.classList.toggle('dark');
	cursor_b.classList.toggle('dark');
	cursor_c.classList.toggle('dark');
	asdfasdf.classList.toggle('dark');
	songs.classList.toggle('dark');
	snake.classList.toggle('dark');
	b_b.classList.toggle('dark');
	document.querySelector('.ball').classList.toggle('dark');
	document.querySelector('.지뢰').classList.toggle('dark');
	document.querySelector('.mine_sweeper input#submitted').classList.toggle('dark');
});

/*document.querySelector('.navbar_menu li').forEach(link => {
	link.addEventListener('mouseover', () =>{
		cursor.classList.remove("link-grow")
	})
	link.addEventListener('mouseover', () =>{
		cursor.classList.add("link-grow")
	})
});*/

toggleBtn.addEventListener('click', () => {
	//p-switch click
	menu.classList.toggle('active');
	icons.classList.toggle('active');
})

HomeWorkMenu_a.addEventListener('click', () => {
	homeworks_a.classList.toggle('active');
})
HomeWorkMenu_b.addEventListener('click', () => {
	homeworks_b.classList.toggle('active');
})

document.querySelector('.needs_subject_a').addEventListener('click', () => {
	//show needs_subject
	document.querySelector('.needs_subject_a ol').classList.toggle('active');
})

document.querySelector('.needs_subject_b').addEventListener('click', () => {
	//show needs_subject
	document.querySelector('.needs_subject_b ol').classList.toggle('active');
})

document.querySelector('.needs_subject_c').addEventListener('click', () => {
	//show needs_subject
	document.querySelector('.needs_subject_c ol').classList.toggle('active');
})

schedulebtn.addEventListener('click', () => {
	schedule.classList.toggle('active')
})

home_workbtn.addEventListener('click', () => {
	home_work.classList.toggle('active')
})

needs.addEventListener('click', () => {
	document.querySelector('.needs_main').classList.toggle('active')
})

songs.addEventListener('click', () => {
	document.querySelector('.music_player').classList.toggle('active')
})

snake.addEventListener('click', () => {
	document.querySelector('.snake').classList.toggle('active')
})

b_b.addEventListener('click', () => {
	document.querySelector('.break_block').classList.toggle('active')
})

document.querySelector('.지뢰').addEventListener('click', () =>{
	document.querySelector('.mine_sweeper').classList.toggle('active')
})

asdfasdf.addEventListener('click', () => {
	//show '기초웹'
	document.querySelector('.asdfasdf_main').classList.toggle('active');
	cursor.classList.toggle('cursor_active');
	cursor_a.classList.toggle('cursor_active');
	cursor_b.classList.toggle('cursor_active');
	cursor_c.classList.toggle('cursor_active');
	//a.classList.toggle('cursor_active');
	document.body.classList.toggle('cursor_active');
	//section.classList.toggle('cursor_active');
	document.querySelector('.navbar.').classList.toggle('cursor_active');
	document.querySelector('.label').classList.toggle('cursor_active');
})

//jquery
$(function(){
	$('.search .icon').click(function(){//icon을 클릭했을 때
		$('.search').toggleClass('active');//search를 active로 토글함
	})
});

$(function(){
	$('.login-_ .icon').click(function(){//icon을 클릭했을 때
		$('.login').toggleClass('active');//search를 active로 토글함
		$('.login-_').toggleClass('active');
	})
});

/*window.addEventListener("mousemove", mouseCursor);

function mousecursor(e) {
	cursor.style.top = (e.pageY-10) + "px"
	cursor.style.left = (e.pageX-10) + "px"
}
===*/