
// Java program to create a blank text
// field of definite number of columns.
import java.awt.event.*;
import javax.swing.*;

class text extends JFrame implements ActionListener {
    // JTextField
    static JTextField t;
    static JFrame f;
    static JButton b;
    static JLabel l;

    // default constructor
    text() {
    }

    if(time == 10){
        prinf("You can go out");
    }
    else if(time )

    // main class
    public static void main(String[] args) {
        // create a new frame to store text field and button
        f = new JFrame("textfield");

        // create a label to display text
        l = new JLabel("Pound");

        // create a new button
        b = new JButton("submit");

        // create a object of the text class
        text te = new text();

        // addActionListener to button
        b.addActionListener(te);

        // create a object of JTextField with 16 columns
        t = new JTextField(16);

        // create a panel to add buttons and textfield
        JPanel p = new JPanel();

        // add buttons and textfield to panel
        p.add(t);
        p.add(b);
        p.add(l);

        // add panel to frame
        f.add(p);

        // set the size of frame
        f.setSize(300, 300);

        f.show();
    }

    // if the button is pressed
    public void actionPerformed(ActionEvent e) {
        String s = e.getActionCommand();
        if (s.equals("submit")) {
            double pound = Double.parseDouble(t.getText());
            // set the text of the label to the text of the field
            double kilogram = pound / 2.2046;

            l.setText("KiloGrams : " + String.format("%.4f", kilogram));

            // set the text of field to blank
            t.setText(" ");
        }
    }
}