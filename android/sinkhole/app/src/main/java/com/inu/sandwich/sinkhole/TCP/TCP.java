package com.inu.sandwich.sinkhole.TCP;

import android.os.Handler;
import android.os.Message;
import android.text.format.Formatter;
import android.util.Log;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.InetAddress;
import java.net.NetworkInterface;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketException;
import java.util.Enumeration;

/**
 * Created by 0xFF00FF00 on 2016-04-01.
 */
public class TCP {

    public class ClientInfo{
        public Socket clientSocket;
        public BufferedReader readBuf;
        public PrintWriter writeBuf;

        public ClientInfo(Socket _client){
            try {
                clientSocket = _client;
                readBuf = new BufferedReader(new InputStreamReader(_client.getInputStream()));
               // String str = in.readLine();
                writeBuf = new PrintWriter(new BufferedWriter(new OutputStreamWriter(_client.getOutputStream())), true);
                //out.println("Server Received " + str);
            } catch (Exception e) {
            }
        }

        public void close(){
            if(clientSocket != null){
                try {
                    clientSocket.close();
                    readBuf.close();
                    writeBuf.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }


    private static final int PORT = 27015;
    private static String TAG = "TCP";

    private ClientInfo clientInfo;

    private Thread ServerThread;
    private Thread ReadThread;

    private Handler handler = null;

    public void setHandler(Handler _handler){
        handler = _handler;
    }

    public static String getLocalIpAddress() {
        try {
            for (Enumeration<NetworkInterface> en = NetworkInterface.getNetworkInterfaces(); en.hasMoreElements();){
                NetworkInterface intf = en.nextElement();
                for (Enumeration<InetAddress> enumIpAddr = intf.getInetAddresses(); enumIpAddr.hasMoreElements();) {
                    InetAddress inetAddress = enumIpAddr.nextElement();
                    if (!inetAddress.isLoopbackAddress()) {
                        String ip = Formatter.formatIpAddress(inetAddress.hashCode());
                        Log.i(TAG, "***** IP=" + ip);
                        return ip;
                    }
                }
            }
        } catch (SocketException ex) {
            Log.e(TAG, ex.toString());
        }
        Log.i(TAG, "***** IP=");
        return null;
    }

    public boolean startTCPServer(){
        if(ServerThread != null ){
            ServerThread.interrupt();
            ServerThread = null;
        }

        try {
            Runtime.getRuntime().exec("adb forward tcp:"+PORT+" tcp:"+PORT);
        }catch (Exception e){
            Log.e("TCP","ee : "+e);
            return false;
        }

        ServerThread = new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    Log.d(TAG, "S: Connecting...");
                    ServerSocket serverSocket = new ServerSocket(PORT);

                    while (true) {
                        final Socket client = serverSocket.accept();
                        if(clientInfo!= null) {
                            clientInfo.close();
                            if(ReadThread != null ){
                                ReadThread.interrupt();
                                ReadThread = null;
                            }
                        }
                        clientInfo = new ClientInfo(client);
                        ReadThread = new Thread(new Runnable() {
                            @Override
                            public void run() {
                                while(true){
                                    try {
                                        Log.d(TAG, "S: readLine...");
                                        String str = clientInfo.readBuf.readLine();
                                        if(str.equals("startDroneImage")){
                                            handler.sendMessage(handler.obtainMessage(0, "startDroneImage"));
                                            Log.d(TAG, "startDroneImage");
                                            while(true){
                                                char[] buf = new char[514];
                                                int size = clientInfo.readBuf.read(buf, 0, 100*100);
                                                Log.d(TAG,"size : "+size);
                                                if(size < 400){
                                                    Log.d(TAG, "f(buf.length < 500)");
                                                    return ;
                                                }
                                                handler.sendMessage(handler.obtainMessage(-1, buf));
                                            }
                                        }else {
                                            Log.d(TAG, "S: sendMessage ..." + str + ";" + str.length() + "," + str.getBytes().toString());
                                            if( str.length() < 1 )
                                                str = "act;MainActivity";
                                            handler.sendMessage(handler.obtainMessage(str.length(), str));
                                        }
                                    } catch (Exception e) {
                                        clientInfo.close();
                                        clientInfo = null;
                                        return ;
                                    }
                                }
                            }
                        });

                        ReadThread.start();
                    }
                } catch (Exception e) {
                    Log.d(TAG, "S: Error");
                    e.printStackTrace();
                }
            }
        });

        ServerThread.start();

        return true;
    }

    public boolean sendMessage(String msg){
        if(clientInfo!= null) {
            clientInfo.writeBuf.println(msg);
            return true;
        }
        return false;
    }

}
