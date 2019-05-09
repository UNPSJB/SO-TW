// Proc_A.java
public class Proc_A extends Thread {

	Mon mon;

	public Proc_A( Mon m ) {
		mon = m;
	}

	public void run() {
		System.out.println( "Start Proc_A" );
		for( int i = 0; i < 1000000; ++i )
			mon.incIndice();
		System.out.println( "End Proc_A" );
		mon.chau();
	}
}

