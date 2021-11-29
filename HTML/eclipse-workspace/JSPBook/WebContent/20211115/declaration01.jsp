<html>
<head>
<title> Scripting Tag </title>
</head>
<body>
	<%! /*int sum(int a, int b){
			return a+b;
		}
		String Lower(String a){
			return a.toLowerCase();
		}
		String Upper(String a){
			return a.toUpperCase();
		}*/
		boolean is_odd(int i){
			return i%2==0;
		}
		%>
	<%
		/*double data = 0;
		for(double i=1;i<=100;i+=4){
			data+=(4/i-4/(i+2));
		}
		out.println("Value of the variable is:" + data+"<br>");
		out.println("2 + 3 = " + sum(2, 3)+"<br>");
		out.println(Lower("Hello World!")+"<p/>");
		out.println(Upper("Hello World!"));*/
		for(int i=0;i<=10;i++){
			out.println(is_odd(i)?i+"<br>":"");
		}
	%>
</body>
</html>