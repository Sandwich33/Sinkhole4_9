package com.inu.sandwich.sinkhole.TCP;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.net.Uri;
import android.os.Environment;
import android.os.Handler;
import android.os.Message;
import android.text.format.Formatter;
import android.util.Log;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.InetAddress;
import java.net.NetworkInterface;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketException;
import java.nio.ByteBuffer;
import java.nio.CharBuffer;
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

    public File getTempFile( File cachdir, String fileName){
        File file=null;
        try{
            file = File.createTempFile( fileName, ".bmp", cachdir);
        }catch( IOException e){

        }
        return file;
    }

    public boolean startTCPServer(final File cachdir){
        if(ServerThread != null ){
            ServerThread.interrupt();
            ServerThread = null;
        }

//        try {
//            Runtime.getRuntime().exec("adb forward tcp:"+PORT+" tcp:"+PORT);
//        }catch (Exception e){
//            Log.e("TCP","ee : "+e);
//            return false;
//        }

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
                                            int count=0;
                                            while(true)
                                            {
                                              //  ByteArrayOutputStream byteArrayOutputStream = new ByteArrayOutputStream();
                                                //Bitmap bmp = BitmapFactory.decodeStream(clientInfo.readBuf);
                                                //File file = getTempFile(cachdir,"temp");
                                                char[] buf = new char[1048630];
                                                int len;
                                                int offset = 0;
                                                int max = 1048630;

                                                do{
                                                    int size = clientInfo.readBuf.read(buf,offset,1024);
                                                    if( size < 0)
                                                        break;
                                                    if( offset == 0 ){
                                                        Log.d(TAG,"["+buf[0]+""+buf[1]+""+buf[2]+"]");
                                                    }
                                                    offset += size;
                                                    max -= size;
                                                    Log.d(TAG,"size "+size+"; offset "+offset+"; max "+max+"; 1048630");
                                                }while(offset < 1048630);
                                                FileWriter fileWriter = new FileWriter( new File(Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_PICTURES), "temp_"+count+".bmp"));
                                                Log.d(TAG, (new File(Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_PICTURES), "temp_"+count+".bmp")).getAbsolutePath());
                                                fileWriter.write(buf,0,offset);
                                                fileWriter.close();
                                                handler.sendMessage(handler.obtainMessage(-1, count,0));
                                                count = (count+1)%10;
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
