class Node {
    int data;
    Node next;

    public Node(int data) {
        this.data = data;
        next = null;
    }
}

class LinkedList {
    Node head = null;

    public void add(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
        } else {
            Node current = head;
            while (current.next != null) {
                current = current.next;
            }
            current.next = newNode;
        }
    }

    public void addFirst(int i) {
        Node newNode = new Node(i);
        newNode.next = head;
        head = newNode;
    }

    public void printValues() {
        Node current = head;
        while (current != null) {
            System.out.print(current.data + " -> ");
            current = current.next;
        }
        System.out.println("null");
    }
}

class Main {
    public static void main(String[] args) {
        LinkedList Mihir = new LinkedList();
        Mihir.addFirst(67);
        Mihir.add(10);
        Mihir.add(20);
        Mihir.printValues();
    }
}

