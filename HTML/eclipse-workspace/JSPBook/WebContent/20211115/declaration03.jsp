<html>
<head>
<title> Scripting Tag </title>
</head>
<body>
	<%! 
		/*boolean event(int a){
			return a%2==0;
		}*/
		
		/*int event(int a){
			return a%2;
		}*/
		
		/*String event(int a){
			if(a%2==0)
				return (a+"<br>");
			else return "";
		}*/
		
		String event(int a){
			return a%2==0?a+"<br>":"";
		}
	%>
	<%
		/*for(int i=0;i<=10;i++){
			out.println(event(i)?i+"<br>":"");
		}*/
		
		/*for(int i=0;i<10;i++){
			if(event(i)==0)
				out.println(i+"<br>");
		}*/
		
		/*for(int i=0;i<=10;i++){
			out.println(event(i));
		}*/
		
		for(int i=0;i<=10;i++){
			out.println(event(i));
		}
	%>
</body>
</html>