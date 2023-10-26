package multithreading;

public class OutOfMemoryNativeThread {
	public static void main(String args[]) {

		while(true) {
			new Thread(new Runnable() {
				public void run() {
					//try {
						for (int i=0;i<10;i++) {
							System.out.print(i);
							System.out.print("\n");
						}
					// } catch(InterruptedExecution e)
				}
			}).start();
		}
	}
}
