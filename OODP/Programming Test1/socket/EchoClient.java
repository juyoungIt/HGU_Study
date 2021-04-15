import java.io.*;
import java.net.*;
import java.util.Scanner;

class EchoClinet {
	public static void main(String[] args) {
		String host = "localhost";

		try {
			// make connection
			Socket socket = new Socket(host, 8008);

			// for send, receive
			BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
			PrintWriter out = new PrintWriter(new OutputStreamWriter(socket.getOutputStream()));
			Scanner key = new Scanner(System.in); // for keyboard input

			boolean clientStatus = false;
			boolean serverStatus = false; // for termination condition

			while(true) {
				System.out.println("Write a Message to Server.");
				String msg = key.nextLine();
				out.println(msg);
				out.flush(); // clean the buffer
				if(msg.equals("bye"))
					clientStatus = true;

				System.out.println("Reading the message from Server.");
				String str = in.readLine();
				System.out.println("Server says: " + str);
				if(str.equals("bye"))
					serverStatus = true;

				if(clientStatus == true && serverStatus == true)
					break;
			}
			socket.close(); // disconnect
		}
		catch(Exception e) {
			e.printStackTrace();
		}
		System.out.println("The EchoClient was closed.");
	}
}
