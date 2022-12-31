import java.net.*;

import java.io.*;



class ThreadJoining extends Thread

{

	Socket s;

	

	ThreadJoining(Socket si) {

		s = si;

	}



	@Override

	public void run()

	{

	try {

		

		Thread.sleep((long)Math.random() * 1000);

		InputStream is=s.getInputStream();

		InputStreamReader isr=new InputStreamReader(is);

		BufferedReader br=new BufferedReader(isr);



		OutputStream os= s.getOutputStream();

		PrintWriter pw=new PrintWriter(os,true);



		String line=br.readLine();

		pw.println("Hello "+line);



		s.close();

	}

	catch (Exception e) {

		System.out.print(e);

	}

	}

}



public class EchoServer {



public static void main(String args[])

{

ThreadJoining var;

try {

ServerSocket ss=new ServerSocket(2222);

System.out.println("Server Socket Created...");

while(true)

{

	Socket s=ss.accept();

	System.out.println("Connection request received...");

	var = new ThreadJoining(s);

	var.start();

}

}catch(Exception e)

{System.out.print(e);}



}

}