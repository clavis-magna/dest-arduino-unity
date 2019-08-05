//a base script to reuse as seen in geobio at bearwarp.com


using UnityEngine;
using System.IO.Ports;
using System.Threading;
using System;


public class ReadArduino : MonoBehaviour
{

    private Thread thread;         
    public string ctrlRead;      
    private bool isThreadRunning;

    public string Com;  // COM port of USB that arduino is using
    SerialPort stream;

    private void Awake()
    {
        ctrlRead = "";
    }
    void Start()
    {
        stream = new SerialPort(Com, 9600);
        if (Com != "")
        {
            thread = new Thread(new ThreadStart(ThreadLoop));        
            thread.IsBackground = true;             
            thread.Start();

            stream.ReadTimeout = 10;
            stream.Open();
        }
    }
    void ThreadLoop()
    {
        isThreadRunning = true;
        while (isThreadRunning)
        {
            try
            {
                // Read from Arduino
                ctrlRead = stream.ReadLine();
            }
            catch (Exception e)
            {
                Debug.LogWarning("Exception: " + e.Message + " " + e.StackTrace);
                ctrlRead = "";
            }
        }
    }                                    
        
    void Update()
    {
        if (stream.IsOpen && isThreadRunning && ctrlRead != "")
        {
            print(ctrlRead);
//            string[] Controls = ctrlRead.Split(',');
            //if (Controls.Length >= 1)
            //{
            //    if (Controls[1] != "")
            //    {
            //        //AnsMachineVol = int.Parse(Controls[1]);
            //    }
            //}
        }
    }

    void OnApplicationQuit()
    {
        if (Com != "")
        {
            isThreadRunning = false;
            thread.Join();
            stream.Close();
        }
    }
}
