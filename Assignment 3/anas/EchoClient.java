import java.net.*;

import javax.swing.JOptionPane;



import java.io.*;

public class EchoClient {

public static void main(String args[])

{try {

	ServerSocket s=new ServerSocket(2222);

	InputStream is=s.getInputStream();

	InputStreamReader isr=new InputStreamReader(is);

	BufferedReader br=new BufferedReader(isr);



	OutputStream os= s.getOutputStream();

	PrintWriter pw=new PrintWriter(os,true);

	String name=args[0];

	pw.println(name);

	

	String line=br.readLine();

	System.out.println(line);

s.close();

}catch(Exception e)

{System.out.print(e);}



}

	

}