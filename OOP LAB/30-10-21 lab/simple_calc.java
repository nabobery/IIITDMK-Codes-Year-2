import java.awt.*;
import java.awt.event.*;
import java.applet.*;

public class simple_calc extends Applet implements ActionListener,KeyListener
{
    Button b9,b1,b3,bplus,bclear,bequal;
    Button b[]=new Button[10];
    TextField tf;
    String number1="";
    String number2="";
    String Op="";

    public void init()
    {
        tf=new TextField();  
        tf.setBounds(100,40,300,60);  

        
        b1=new Button("1");  
        b1.setBounds(100,120,60,50);  
        b3=new Button("3");  
        b3.setBounds(200,120,60,50);
        b9=new Button("9");  
        b9.setBounds(300,120,60,50);
        bplus=new Button("+");  
        bplus.setBounds(400,120,60,50); 
        bequal=new Button("=");  
        bequal.setBounds(500,120,60,50);
        bclear=new Button("C");  
        bclear.setBounds(600,120,60,50);

        // Try this method also for creating buttons using array of objects
        // for(int i=0;i<10;i++)
        // {
        //     b[i]=new Button(""+i);
        //     b[i].setBounds(10+i*60,240,60,50);
        //     add(b[i]);
        //     b[i].addActionListener(this); 
        //     b[i].addKeyListener(this);  
        // }
        
        
        
        add(b1);
        add(b3);
        add(b9);
        add(bplus);
        add(bequal);
        add(bclear);
        add(tf);  

        b1.addActionListener(this);  
        b3.addActionListener(this);  
        b9.addActionListener(this); 
        bplus.addActionListener(this);  
        bequal.addActionListener(this);  
        bclear.addActionListener(this);  
       

        b1.addKeyListener(this);  
        b3.addKeyListener(this);  
        b9.addKeyListener(this);  
        bplus.addKeyListener(this);  
        bequal.addKeyListener(this);  
        bclear.addKeyListener(this); 
        tf.addKeyListener(this); 
    
        setLayout(null);  
    }

    public void keyTyped(KeyEvent e) 
    { 
            //
    }  
    public void keyReleased(KeyEvent e) 
    { 
                //
    }  
    public void keyPressed(KeyEvent e) 
    { 
            if(e.getKeyChar()=='C')
            tf.setText("");
            else if( (e.getKeyCode()>=96 && e.getKeyCode()<=105) || (e.getKeyCode()>=48 && e.getKeyCode()<=57) )
            {
                number1+=e.getKeyChar();
                tf.setText(number1); 
            }
            
            else if(e.getKeyChar()=='+')
            {
                
                number2="";
                number2+=number1;
                number1="";
                Op="+";
            }
            else if(e.getKeyChar()=='=' || e.getKeyCode()==10 )
            {
                if(Op.equals("+"))
                {
                    if(!number1.equals("") && !number2.equals(""))
                    {
                    int x=Integer.parseInt(number1);
                    int y=Integer.parseInt(number2);
                    tf.setText(""+(x+y));
                    }
                }
                Op="";
                
                
            }
            else{
                //
            }
    } 
    public void actionPerformed(ActionEvent e)
    {  
            if(e.getActionCommand()=="C")
            tf.setText("");
            else if(e.getActionCommand()=="1" || e.getActionCommand()=="3" || e.getActionCommand()=="9" )
            {
                number1+=e.getActionCommand();
                tf.setText(number1); 
            }
            
            else if(e.getActionCommand()=="+")
            {
                
                number2="";
                number2+=number1;
                number1="";
                Op="+";
            }
            else if(e.getActionCommand()=="=")
            {
                if(Op.equals("+"))
                {
                    if(!number1.equals("") && !number2.equals(""))
                    {
                    int x=Integer.parseInt(number1);
                    int y=Integer.parseInt(number2);
                    tf.setText(""+(x+y));
                    }
                }
                Op="";
                
                
            }
            else{
                //
            }
            
 
    }   
}

/* 
<applet code="simple_calc.class" width="800" height="600"> 
</applet> 
*/  