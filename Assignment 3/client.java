import java.net.*;
import javax.swing.JOptionPane;

import java.io.*;
public class client {
public static void main(String args[])
{try {
	Socket s=new Socket("localhost",2222);
	InputStream is=s.getInputStream();
	InputStreamReader isr=new InputStreamReader(is);
	BufferedReader br=new BufferedReader(isr);

	OutputStream os= s.getOutputStream();
	PrintWriter pw=new PrintWriter(os,true);
    String name="Hello my name is Saboor";
	pw.println(name);
	
	String line=br.readLine();
	JOptionPane.showMessageDialog(null, line);
s.close();
}catch(Exception e)
{System.out.print(e);}

}
	
}