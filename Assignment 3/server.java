import java.net.*;
import javax.swing.JOptionPane;
import java.io.*;
public class server {

public static void main(String args[])
{try {
ServerSocket ss=new ServerSocket(2222);
System.out.println("Server Socket Created...");
while(true)
{
Socket s=ss.accept();
System.out.println("Connection request received...");
InputStream is=s.getInputStream();
InputStreamReader isr=new InputStreamReader(is);
BufferedReader br=new BufferedReader(isr);

OutputStream os= s.getOutputStream();
PrintWriter pw=new PrintWriter(os,true);

String line=br.readLine();
pw.println(line);

s.close();
}
}catch(Exception e)
{System.out.print(e);}

}
}
