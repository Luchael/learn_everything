<%@page contentType = "test/html; charset=utf-8"%>
<%@ page import="java.util.Date"%>
<html>
<head>
<title>Action Tag</title>
</head>
<body>
	<h3>이 파일은 second.jsp입니다.</h3>
	Today is : <%=new java.util.Date()+"<br>"%>
	<%
	Date day = new java.util.Date();
	String am_pm;
	int hour = day.getHours();
	int minute = day.getMinutes();
	int second = day.getSeconds();
	String CT = hour + ":" + minute + ":" + second;
	out.println("현재 접속 시각:" + CT + "\n");
	%> 
	<jsp:include page="third.jsp" flush = "false"/>
	
</body>
</html>