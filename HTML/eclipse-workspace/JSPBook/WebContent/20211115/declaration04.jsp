<html>
<head>
<title>Scripting Tag</title>
</head>
<body>
	<p>
		Today's date:
		<%= new java.util.Date()%>
		<%
			int a = 10;
			int b = 20;
			int c = 30;
			out.println("<br>a+b+c: ");
		%>
		<%= a+b+c %>
	</p>
</body>
</html>