public class Queue {
	private Node tail;
	private Node head;
	private int size;

	public Queue() {
		head = null;
		tail = null;
		size = 0;
	}

	public boolean isEmpty(){
		if (head == null) return true;
		return false;
	}
	
	public void enqueue(String data) {
		Node n = new Node(data);
		if (head == null) {
			head = n;
			tail = n;
		} else {
			tail.next = n;
			tail = n;
		}

		size++; 
	}

	public int dequeue() {
		if (isEmpty()) {
			System.out.println("Queue is empty");
			System.exit(1);
		}
		if (head == tail) {
			tail = null;
		}
		int data = head.num;
		head = head.next;
		size--;
		return data;
	}

	public int getSizeQueue() {return size;}

	public Node traverse(boolean print) {
		Node curr = head;

		while (curr != null) {
			if (print) System.out.print(curr.num + " ");
			curr = curr.next;
		}
		if (print) System.out.println();

		return head;
	}

	public boolean find(int n) {
		Node curr = head;

		while (curr != null) {
			System.out.println(curr.num + " vs " + n);
			if (curr.num == n) return true;
			curr = curr.next;
		}
		return false;
	}
	
}
