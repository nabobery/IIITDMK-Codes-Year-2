import java.awt.*;
import java.applet.*;
import java.awt.event.*;

// A class that contains our main calculator program
public class exp extends Applet implements ActionListener
{
    TextField input;
    //A Function to add features to the frame such as text field, buttons etc
    public void init()
    {
        setBackground(Color.white);
        setLayout(null);
        // Adding a textfield for viewing input and output
        input = new TextField();
        input.setBounds(150,100,375,75);
        input.setFont(new Font("Arial", Font.PLAIN, 20));
        input.setBackground(new Color(18, 18, 18));
        input.setForeground(Color.white);
        this.add(input);
        // Creating buttons for input numbers
        Button b[] = new Button[10];
        for(int i=0;i<10;i++){
            b[i] = new Button(String.valueOf(9-i));
            b[i].setBounds(150+((i%3)*75),175+((i/3)*75),75,75);
            b[i].setFont(new Font("Arial", Font.BOLD, 20));
            b[i].setForeground(new Color(98, 255, 187));
            b[i].setBackground(new Color(18, 18, 18));
            this.add(b[i]);
            b[i].addActionListener(this);
        }
        Button decimal = new Button(".");
        decimal.setBounds(225,400,75,75);
        decimal.setFont(new Font("Arial", Font.BOLD, 20));
        decimal.setForeground(new Color(98, 255, 187));
        decimal.setBackground(new Color(18, 18, 18));
        this.add(decimal);
        decimal.addActionListener(this);
        Button clear = new Button("C");
        clear.setBounds(300,400,75,75);
        clear.setFont(new Font("Arial", Font.BOLD, 20));
        clear.setForeground(new Color(98, 255, 187));
        clear.setBackground(new Color(18, 18, 18));
        this.add(clear);
        clear.addActionListener(this);
        // Creating buttons for operators
        Button operator[] = new Button[5];
        operator[0] = new Button("/");
        operator[1] = new Button("*");
        operator[2] = new Button("-");
        operator[3] = new Button("+");
        operator[4] = new Button("=");
        for(int i=0;i<4;i++){
            operator[i].setBounds(375,175+(i*75),75,75);
            this.add(operator[i]);
            operator[i].addActionListener(this);
            operator[i].setForeground(new Color(253, 73, 0));
            operator[i].setFont(new Font("Arial", Font.BOLD, 22));
            operator[i].setBackground(new Color(18, 18, 18));
        }
        operator[4].setBounds(450,400,75,75);
        this.add(operator[4]);
        operator[4].setForeground(new Color(253, 73, 0));
        operator[4].setBackground(Color.black);
        operator[4].setFont(new Font("Arial", Font.BOLD, 22));
        operator[4].addActionListener(this);
        Button temp[] = new Button[3];
        for(int i=0;i<3;i++){
            temp[i] = new Button(" ");
            temp[i].setBounds(450,175+(i*75),75,75);
            this.add(temp[i]);
            temp[i].setBackground(new Color(18, 18, 18));
        }
    }
    String number1="";
    String operator="";
    String number2="";
    //A Function to evaluate the expression
    public void actionPerformed(ActionEvent e)
    {
        String button = e.getActionCommand();
        char ch = button.charAt(0);
        if(ch>='0' && ch<='9'|| ch=='.'){
            if (!operator.equals(""))
                number2 = number2 + button;
            else
                number1 = number1 + button;
            input.setText(number1+operator+number2);
        }
        else if(ch=='C'){
            number1 = operator = number2 = "";
            input.setText("");
        }
        else if (ch =='=') {
            if(!number1.equals("") && !number2.equals("")){
                double temp;
                double num1=Double.parseDouble(number1);
                double num2=Double.parseDouble(number2);
                if(num2 == 0 && operator.equals("/")){
                    input.setText(number1+operator+number2+" = Zero Division Error");
                    number1 = operator = number2 = "";
                }
                else{
                    if (operator.equals("+"))
                        temp = num1 + num2;
                    else if (operator.equals("-"))
                        temp = num1 - num2;
                    else if (operator.equals("/"))
                        temp = num1/num2;
                    else
                        temp = num1*num2;
                    input.setText(number1+operator+number2+" = "+ temp);
                    number1 = Double.toString(temp);
                    operator = number2 = "";
                }
            }
            else{
                number1 = operator = number2 = "";
                input.setText("");
            }
        }
        else{
            if (operator.equals("") || number2.equals(""))
                operator = button;
            else{
                double temp;
                double num1=Double.parseDouble(number1);
                double num2=Double.parseDouble(number2);
                if(num2==0 && operator.equals("/")){
                    input.setText(number1+operator+number2+" = Zero Division Error");
                    number1 = operator = number2 = "";
                }
                else{
                    if (operator.equals("+"))
                        temp = num1 + num2;
                    else if (operator.equals("-"))
                        temp = num1 - num2;
                    else if (operator.equals("/"))
                        temp = num1/num2;
                    else
                        temp = num1*num2;
                    number1 = Double.toString(temp);
                    operator = button;
                    number2 = "";
                }
            }
            input.setText(number1+operator+number2);
        }
    }
}

/*
<applet code = exp.class width=800 height=600>
</applet>
*/