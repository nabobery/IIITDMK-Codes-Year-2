// This program is done by CS20B1044 Avinash R Changrani
import java.applet.Applet; 
import java.awt.*;

public class program extends Applet{

    public void paint(Graphics g){
        // origin co-ordinates of the window
        int x = getX();
        int y = getY();
        // height and width of the window
        int w = getWidth();
        int h = getHeight();
        Font f1 = new Font("Arial", Font.BOLD, 22);
        // An oval at the top right
        g.drawOval(x + w - 300,y,300,200);
        g.setColor(new Color(0,255,255));
        // An oval inside the oval at the top right
        g.fillOval(x + w - 190,y + 20,80,160);
        g.setColor(new Color(255, 0, 255));
        // A filled rectangle at the bottom left
        g.fillRect(x,h - 160,240,160);
        g.setColor(Color.green);
        // A rectangle inside the filled rectangle at the bottom left
        g.drawRect(x + 60,h - 120,120,80);
        g.setColor(Color.red);
        // A circle at the Center
        g.fillOval(w/2 - 125 , h/2 - 125 ,250, 250);
        g.setColor(Color.yellow);
        g.setFont(f1);
        // String in the Circle
        g.drawString("CS20B1044", w/2 - 50, h/2 - 5);
        g.drawString("Avinash R Changrani", w/2 - 100, h/2 + 18);
    }
}

/* 
<applet code="program.class" width="1024" height="720"> 
</applet> 
*/  