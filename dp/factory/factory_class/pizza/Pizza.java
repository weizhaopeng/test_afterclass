package factory.factory_class.factory_class.pizza;

public abstract class Pizza {
	int size;
	String from;
	String name;

	abstract void prepare();
	void cut() {
		System.out.println("cut the pizza into 8 block");
	}
	void cook() {
		System.out.println("cook the pizza");
	}
	void fetch() {
		System.out.println("wattess fetch the pizza");
	}
}


