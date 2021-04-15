import java.io.*;
import java.net.*;
import java.util.Scanner;

class EchoServer {
	public static void main(String[] args) {
		System.out.println("EchoServer Started.");

		try {
			ServerSocket s = new ServerSocket(8008);
			Socket socket = s.accept();

			System.out.println("Connected to: " + socket.getInetAddress() + " at port: " + socket.getLocalPort());

			// create for send and receive
			Scanner key = new Scanner(System.in); // for keyboard input
			BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
			PrintWriter out = new PrintWriter(new OutputStreamWriter(socket.getOutputStream()));

			boolean clientStatus = false; // terminate status 1
			boolean serverStatus = false; // terminate status 2

			while(true) {
				System.out.println("Reading the Message From a Client.");
				String str = in.readLine();
				System.out.println("Client says: " + str);
				if(str.equals("bye"))
					clientStatus = true;

				System.out.println("Write the message for client.");
				String msg = key.nextLine(); // read the message
				out.println(msg);
				out.flush(); // clear the buffer
				if(msg.equals("bye"))
					serverStatus = true;

				// termination check
				if(clientStatus == true && serverStatus == true)
					break;
			}
			socket.close(); // disconnect
		}
		catch(Exception e) {
			e.printStackTrace();
		}
		System.out.println("The EchoServer was stopped.");
	}
}
