import java.applet.Applet; 
import java.awt.Color; 
import java.awt.Graphics;  
import java.lang.*;
//import java.io.*;

public class exp extends Applet{

    public void paint(Graphics g){
        int[] coordinates = new int[2];
        int x = getX();
        int y = getY();
        int w = getWidth();
        int h = getHeight();
        /*System.out.println(w);
        System.out.println(h);
        String width = Integer.toString(w);
        String height = Integer.toString(h);
        g.drawString(width,100,100);
        g.drawString(height,200,200);*/
        g.drawOval(x + w - 150,y,150,100);
        g.setColor(new Color(0,255,255));
        g.fillOval(x + w - 115,y + 30,80,40);
        g.setColor(new Color(255, 0, 255));
        g.fillRect(x,h - 80,120,80);
        g.setColor(Color.orange);
        g.drawRect(x + 30,h - 60,60,40);
        g.setColor(Color.red);
        g.fillOval(w/2 - 50 , h/2 -50 ,100, 100);
        g.setColor(Color.yellow);
        g.drawString("CS20B1044", w/2 -30, h/2 - 5);
    }
}

/* 
<applet code="exp.class" width="1024" height="720"> 
</applet> 
*/  