import java.io.*;
import java.net.*;
import java.util.Scanner;

class ClientSide2 {
	public static void main(String[] args) {
		String host = "localhost";

		try {
			// set the connection
			Socket socket = new Socket(host, 8009);

			// set the in/out proxy
			BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
			PrintWriter out = new PrintWriter(new OutputStreamWriter(socket.getOutputStream()));

			Scanner key = new Scanner(System.in);
			
			// Termination condition
			boolean serverStatus = false;
			boolean clientStatus = false;

			while(true) {
				// process the communication
				System.out.println("Write a Message to Server");
				String toServer = key.nextLine();
				out.println(toServer);
				out.flush(); // clean the buffer
				if(toServer.equals("bye"))
					clientStatus = true;
	
				System.out.println("Reading the Message from Server");
				String fromServer = in.readLine();
				System.out.println("Server says: " + fromServer);
				if(fromServer.equals("bye"))
					serverStatus = true;

				if(clientStatus == true && serverStatus == true)
					break;
			}
			socket.close();
		}
		catch(Exception e) {
			e.printStackTrace();
		}
	}
}
