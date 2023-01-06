import javax.swing.*;
import java.awt.*;


public class Inicial
{
	private JFrame Inicial = new JFrame();
	private JLabel l = new JLabel();
	private Font f = new Font("Arial", Font.ITALIC, 12);
	
	private JTextField nome = new JTextField();
	
	public Inicial()
	{	
		Inicial.setSize(300,440);
		Inicial.setLocationRelativeTo(null);
		Inicial.setVisible(true);
		Inicial.setLayout(null);
		
		l.setText("Controle de Portaria");
		l.setBounds(85,5,150,10);
		l.setForeground(Color.BLUE);
		l.setFont(f);
		
		Inicial.add(l);
		
		nome.setBounds(20,30,150,20);
		nome.setToolTipText("Digite um nome");
		Inicial.add(nome);
	}

}
