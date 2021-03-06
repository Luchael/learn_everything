<%@ page contentType="text/html; charset = UTF-8" pageEncoding="UTF-8"%>
<%@ page import="java.util.Date"%>

<html>
<head>
<link rel="stylesheet"
	href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css">
<title>Welcome</title>
</head>
<body>
	<nav class="navbar navbar-expand navbar-dark bg-dark">
		<div class="container">
			<div class="navbar-header">
				<a class="navbar-brand" href="./welcome.jsp"> home </a>
			</div>
		</div>
	</nav>
	<%!String greeting = "웹 쇼핑몰에 오신 것을 환영합니다!";
	String tagline = "Welcome to Web Market!";%>
	<div class="jumbotron">
		<div class="container">
			<h1 class="display-3">
				<%=greeting%>
			</h1>
		</div>
	</div>
	<main role="main">
		<div class="container">
			<div class="text-left">
				<h3>
					<%=tagline%>
				</h3>

				<%
				Date day = new java.util.Date();
				String am_pm;
				int hour = day.getHours();
				int minute = day.getMinutes();
				int second = day.getSeconds();
				
				String CT = hour + ":" + minute + ":" + second;
				out.println("현재 접속 시각:" + CT + "\n");
				%>
			</div>
		</div>
		<hr>
	</main>
	<footer class="container">
		<p>&copy;WebMarket</p>
		<a title="배재대학교" href="https://pcu.ac.kr">학교</a>
	</footer>
</body>
</html>