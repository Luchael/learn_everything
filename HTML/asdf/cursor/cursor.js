const cursor = document.querySelector('.cursor');
const cursor_a = document.querySelector('.cursor2');
const cursor_b = document.querySelector('.cursor3');
const cursor_c = document.querySelector('.cursor4');

document.addEventListener('mousemove', e => {//마우스가 움직이면
	cursor.setAttribute("style", "top: "+(e.pageY - 10)+"px; left: "+(e.pageX - 10)+"px;")//위에서부터 y좌표 따라서, 왼쪽에서부터 x좌표 따라서 움직임
})

document.addEventListener('mousemove', e => {//마우스가 움직이면
	cursor_a.setAttribute("style", "bottom: "+(e.pageY - 10)+"px; left: "+(e.pageX - 10)+"px;")//위에서부터 y좌표 따라서, 왼쪽에서부터 x좌표 따라서 움직임
})

document.addEventListener('mousemove', e => {//마우스가 움직이면
	cursor_b.setAttribute("style", "bottom: "+(e.pageY - 10)+"px; right: "+(e.pageX - 10)+"px;")//위에서부터 y좌표 따라서, 왼쪽에서부터 x좌표 따라서 움직임
})

document.addEventListener('mousemove', e => {//마우스가 움직이면
	cursor_c.setAttribute("style", "top: "+(e.pageY - 10)+"px; right: "+(e.pageX - 10)+"px;")//위에서부터 y좌표 따라서, 왼쪽에서부터 x좌표 따라서 움직임
})

document.addEventListener('click', () => {//클릭하면
	cursor.classList.add("expand");//expand 를 추가
	setTimeout(() => {
		cursor.classList.remove("expand");//500ms 후에 expand 제거
	}, 500)
	cursor_a.classList.add("expand2");//expand 를 추가
	setTimeout(() => {
		cursor_a.classList.remove("expand2");//500ms 후에 expand 제거
	}, 500)
	cursor_b.classList.add("expand");//expand 를 추가
	setTimeout(() => {
		cursor_b.classList.remove("expand");//500ms 후에 expand 제거
	}, 500)
	cursor_c.classList.add("expand2");//expand 를 추가
	setTimeout(() => {
		cursor_c.classList.remove("expand2");//500ms 후에 expand 제거
	}, 500)
})