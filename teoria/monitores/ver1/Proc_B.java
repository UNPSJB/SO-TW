// Proc_B.java
public class Proc_B extends Thread {

	Mon mon;

	public Proc_B( Mon m ) {
		mon = m;
	}

	public void run() {
		System.out.println( "Start Proc_B" );
		for( int i = 0; i < 1000000; ++i )
			mon.incIndice();
		System.out.println( "End Proc_B" );
		mon.chau();
	}
}

