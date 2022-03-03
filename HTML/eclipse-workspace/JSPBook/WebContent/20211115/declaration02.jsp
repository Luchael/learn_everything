<html>
<head>
<title> Scripting Tag </title>
</head>
<body>
	<%! 
	    int a = 27;
	    int n, m;
	    boolean star(int x, int y) {
		    while (true) {
		        if ((x-1) % 3 == 0 && (y-1) % 3==0) return false;
		        if (x==0|| y==0) return true;
		        return star (x / 3, y / 3);
		    }
		}
	%>
	<%
	    for (n=0; n < a; n++) {
	        for (m = 0; m < a; m++) {
	            out.println(star(n,m) ? '*' : "&nbsp&nbsp");
	        }
	        out.println("<br>");
	    }
	%>
</body>
</html>