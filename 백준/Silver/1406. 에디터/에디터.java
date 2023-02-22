import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static class ListNode {
		char value;
		ListNode prev;
		ListNode next;
		
		public ListNode() {
			this.value='\0';
			this.prev=null;
			this.next=null;
		}
		
		public ListNode(char value,ListNode current) {
			this.value=value;
			this.prev=current;
			this.next=null;
		}
		
		static ListNode createNode(char value,ListNode prev) {
			ListNode newNode=new ListNode(value,prev);
			newNode.prev.next=newNode;
			return newNode;
		}
		
		ListNode deleteNode(ListNode del) {
			if(del.equals(root))
				return root;

			ListNode temp=del.prev;
			temp.next=del.next;
			if(del.next!=null)
				del.next.prev=temp;
			
			return temp;
		}
		
		ListNode insertNode(char value,ListNode current) {
			ListNode insert=new ListNode(value,current);
			
			insert.next=current.next;
			current.next=insert;
			
			if(insert.next!=null)
				insert.next.prev=insert;
			
			return insert;
		}
		
		ListNode left(ListNode current) {
			return current.equals(root)?current:current.prev;
		}
		
		ListNode right(ListNode current) {
			return current.next==null?current:current.next;
		}
	}
	
	public static ListNode root;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb=new StringBuilder();
		String str=br.readLine();
		
		root=new ListNode();
		ListNode current=ListNode.createNode(str.charAt(0),root);
		for(int i=1;i<str.length();i++)
			current=ListNode.createNode(str.charAt(i),current);

		int N=Integer.parseInt(br.readLine());
		for(int n=0;n<N;n++) {
			st=new StringTokenizer(br.readLine());
			switch(st.nextToken().charAt(0)) {
			case 'L':
				current=current.left(current);
				break;
			case 'D':
				current=current.right(current);
				break;
			case 'B':
				current=current.deleteNode(current);
				break;
			case 'P':
				current=current.insertNode(st.nextToken().charAt(0), current);
				break;
			}
		}
		
		root=root.next;
		while(root!=null) {
			sb.append(root.value);
			root=root.next;
		}
		System.out.println(sb.toString());
	}
}