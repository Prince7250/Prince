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



// class Node {

//     int data;
//     Node next;

//     public Node(int data) {
//         this.data = data;
//         this.next = null;
//     }
// }

// class LinkedList {
//     Node head = null;

//     // Add at end
//     public void add(int data) {
//         Node newNode = new Node(data);

//         if (head == null) {
//             head = newNode;
//             return;
//         }

//         Node current = head;
//         while (current.next != null) {
//             current = current.next;
//         }
//         current.next = newNode;
//     }

   
//     public void addFirst(int data) {
//         Node newNode = new Node(data);
//         newNode.next = head;
//         head = newNode;
//     }

    
//     public void delete(int data) {
//         if (head == null) return;

//         if (head.data == data) {
//             head = head.next;
//             return;
//         }

//         Node current = head;
//         while (current.next != null && current.next.data != data) {
//             current = current.next;
//         }

//         if (current.next != null) {
//             current.next = current.next.next;
//         }
//     }

   
//     public void printValues() {
//         Node current = head;
//         while (current != null) {
//             System.out.print(current.data + " ");
//             current = current.next;
//         }
//         System.out.println();
//     }
// }

//  class Student {
//     public static void main(String[] args) {
//         LinkedList list = new LinkedList();

//         list.add(10);
//         list.add(20);
//         list.addFirst(5);
//         list.printValues(); 

//         list.delete(10);
//         list.printValues();  
//     }
// }

