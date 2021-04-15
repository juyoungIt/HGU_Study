import java.io.*;
import java.net.*;
import java.util.Scanner;

class ServerSide {
	public static void main(String[] args) {
		System.out.println("EchoServer Started.");

		try {
			// ready the connect (client1)
			ServerSocket ready1 = new ServerSocket(8008);
			Socket conn1 = ready1.accept();
			System.out.println("Connected to: " + conn1.getInetAddress() + " at port: " + conn1.getLocalPort()); // print connection info
			
			// ready the connect (client2)
			ServerSocket ready2 = new ServerSocket(8009);
			Socket conn2 = ready2.accept();
			System.out.println("Connected to: " + conn2.getInetAddress() + " at port: " + conn2.getLocalPort()); // print connection info

			// make scanner
			Scanner key = new Scanner(System.in);

			// make connection between client1 to server
			BufferedReader inC1 = new BufferedReader(new InputStreamReader(conn1.getInputStream()));
			PrintWriter outC1 = new PrintWriter(new OutputStreamWriter(conn1.getOutputStream()));

			// make connection between clinet2 to server
			BufferedReader inC2 = new BufferedReader(new InputStreamReader(conn2.getInputStream()));
			PrintWriter outC2 = new PrintWriter(new OutputStreamWriter(conn2.getOutputStream()));
			
			boolean serverStatus = false;
			boolean client1Status = false;
			boolean client2Status = false;

			// process the connection
			while(true) {
				// read from client1 
				System.out.println("Reading the Message from Client1.");
				String recC1 = inC1.readLine();
				System.out.println("Client1 says : " + recC1);
				if(recC1.equals("bye"))
					client1Status = true;

				// write to client1
				System.out.println("Write the message for Client1.");
				String sendC1 = key.nextLine();
				outC1.println(sendC1);
				outC1.flush(); // clean the buffer
				if(sendC1.equals("bye"))
					serverStatus = true;
 
				// read from client2 
				System.out.println("Reading the Message from Client2.");
				String recC2 = inC2.readLine();
				System.out.println("Client1 says : " + recC2);
				if(recC2.equals("bye"))
					client2Status = true;

				// write to client2
				System.out.println("Write the message for Client2.");
				String sendC2 = key.nextLine();
				outC2.println(sendC2);
				outC2.flush(); // clean the buffer
				if(sendC1.equals("bye"))
					serverStatus = true;

				// termination check
				if(serverStatus == true && client1Status == true && client2Status == true)
					break;
			}
			conn1.close();
			conn2.close();
		}
		catch(Exception e) {
			e.printStackTrace();
		}
		System.out.println("The server was stopped.");
	}
}
