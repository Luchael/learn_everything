const reader = new FileReader()
let previous = document.querySelector('#pre');
let play = document.querySelector('#play');
let next = document.querySelector('#next');
let title = document.querySelector('#title');
let recent_volume = document.querySelector('#volume');
let volume_show = document.querySelector('#volume_show');
let slider = document.querySelector('#duration_slider');
let show_duration = document.querySelector('#show_duration');
let track_image = document.querySelector('#track_image');
let auto_play = document.querySelector('#auto');
let present = document.querySelector('#present');
let total = document.querySelector('#total');
let artist = document.querySelector('#artist');

let timer;
let autoplay = 0;

let index_no = 0;
let playing_song = false;

//create a audio Element
let track = document.createElement('audio');


//All song list
let All_song = [
	{
		name: "Gusty Garden Galaxy",
		path: "./music/Gusty Garden Galaxy Medley Jazz Arrangement  insaneintherainmusic.mp3",
		img: "./img/img1.jpg",
		singer: "insaneintherainmusic<br>(원곡: Super Mario Galaxy)"
	},
	{
		name: "Win Win",
		path: "./music/Win Win.mp3",
		img: "./img/img2.jpg",
		singer: "various artists"
	},
	{
		name: "Anima",
		path: "./music/Anima.mp3",
		img: "./img/img3.jpg",
		singer: "Xi"
	},
	{
		name: "Battle Against A True Hero",
		path: "./music/Battle Against a True Hero.mp3",
		img: "./img/img4.jpg",
		singer: "Toby Fox"
	},
	{
		name: "Dynamite",
		path: "./music/BTS - Dynamite.mp3",
		img: "./img/img5.jpg",
		singer: "Qubic<br>(원곡: BTS)"
	},
	{
		name: "나라 사랑 노래",
		path: "./music/Nightcore 나라사랑노래.mp3",
		img: "./img/img6.jpg",
		singer: "스카이하이"
	},
	{
		name: "R",
		path: "./music/Plum - R.mp3",
		img: "./img/img7.jpg",
		singer: "Plum"
	},
	{
		name: "The Muffine Song",
		path: "./music/The Muffine Song.mp3",
		img: "./img/img8.jpg",
		singer: "asdfmovie"
	},
	{
		name: "お勉強しといてよ",
		path: "./music/ずっと真夜中でいいのにお勉強しといてよMVZUTOMAYO  STUDY ME.mp3",
		img: "./img/img9.jpg",
		singer: "ずっと真夜中でいいのに。"
	},
	{
		name: "형",
		path: "./music/그렉 - 노라조  형.mp3",
		img: "./img/img10.jpg",
		singer: "그렉<br>(원곡: 노라조)"
	},
	{
		name: "염라",
		path: "./music/달의하루 - 염라.mp3",
		img: "./img/img11.jpg",
		singer: "달의하루"
	},
	{
		name: "너로 피어오라",
		path: "./music/달의하루너로피어오라.mp3",
		img: "./img/img12.jpg",
		singer: "달의하루"
	},
	{
		name: "동화는 무슨",
		path: "./music/동화는 무슨 feat 조매력 땡지 정혜일 뼝아리 천재이승국 김스카이 동그라미.mp3",
		img: "./img/img13.jpg",
		singer: "티키틱"
	},
	{
		name: "망태 할아버지",
		path: "./music/망태 할아버지.mp3",
		img: "./img/img14.jpg",
		singer: "과나"
	},
	{
		name: "매직 카펫 라이드",
		path: "./music/매직 카펫 라이드 자우림 뮤지컬 커버    TIKITIK.mp3",
		img: "./img/img15.jpg",
		singer: "티키틱<br>(원곡: 자우림)"
	},
	{
		name: "丸の内サディスティック",
		path: "./music/丸の内サディスティック Marunouchi Sadistic  COVER by くろくも kurokumo.mp3",
		img: "./img/img16.jpg",
		singer: "くろくも<br>(원곡: 東京事変)"
	},
	{
		name: "뭐 먹을지 고민될 때 부르는 노래",
		path: "./music/뭐 먹을지 고민될 때 부르는 노래 .mp3",
		img: "./img/img17.jpg",
		singer: "티키틱"
	},
	{
		name: "연두부 비빔밥",
		path: "./music/연두부 비빔밥.mp3",
		img: "./img/img18.jpg",
		singer: "과나"
	},
	{
		name: "집 밖에 못 나가서 빡친 노래",
		path: "./music/집 밖에 못 나가서 빡친 노래 교육용.mp3",
		img: "./img/img19.jpg",
		singer: "배카인"
	},
	{
		name: "컬러링",
		path: "./music/컬러링.mp3",
		img: "./img/img20.jpg",
		singer: "티키틱"
	}
]

//All function


//function load the track
function load_track(index_no){
    clearInterval(timer);
    reset_slider();
	track.src = All_song[index_no].path;
	title.innerHTML = All_song[index_no].name;
	track_image.src = All_song[index_no].img;
	artist.innerHTML = All_song[index_no].singer;
	track.load();

    //numbering
    total.innerHTML = All_song.length;
    present.innerHTML = index_no + 1;
    timer = setInterval(range_slider , 1000);
}
load_track(index_no);

//mute sound
function mute_sound(){
    track.volume = 0;
    volume.value = 0;
    volume_show.innerHTML = 0;
}

//reset song slider
function reset_slider(){
    slider.value = 0;
}

//checking the song is playing or not
function justplay(){
	if(playing_song==false){
		playsong();
	}else{
		pausesong();
	}
}


//play song
function playsong(){
	track.play();
	playing_song = true;
	play.innerHTML = '<i class="fa fa-pause"></i>';
}


//pause song
function pausesong(){
	track.pause();
	playing_song = false;
	play.innerHTML = '<i class="fa fa-play"></i>';
}

//next song
function next_song(){
    if (index_no < All_song.length - 1){
        index_no+=1;
        load_track(index_no);
        playsong();
    }else{
        index_no = 0;
        load_track(index_no);
        playsong();
    }
}


//previous song
function previous_song(){
    if (index_no > 0){
        index_no -= 1;
        load_track(index_no);
        playsong();
    }else{
        index_no = All_song.length-1;
        load_track(index_no);
        playsong();
    }
}


//change volume
function volume_change(){
    volume_show.innerHTML = recent_volume.value;
    track.volume = recent_volume.value / 100;
}

//change slider position
function change_duration(){
    slider_position = track.duration * (slider.value / 100);
    track.currentTime = slider_position;
}

//autoplay function
function autoplay_switch(){
    if (autoplay == 1){
        autoplay = 0;
        auto_play.style.background = "rgba(255, 255, 255, 0.2)";
    }else{
        autoplay = 1;
        auto_play.style.background = "#FF8A65";
    }
}

function range_slider(){
    let position = 0;

    //update slider position
    if(!isNaN(track.duration)){
        position = track.currentTime * (100 / track.duration);
        slider.value = position;
    }

    //function will run when the song is over
    if(track.ended){
        play.innerHTML = '<i class="fa fa-play"></i>';
        if (autoplay == 1){
            index_no += 1;
            load_track(index_no);
            playsong();
        }
    }
}