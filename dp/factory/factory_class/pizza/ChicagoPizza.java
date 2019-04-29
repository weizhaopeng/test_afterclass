package factory.factory_class.pizza;

public class ChicagoPizza extends Pizza {
	ChicagoPizza() {
		name = "Chicago pizza";
	}
	void prepare() {
		System.out.println("the Chicago pizza need:"+
			"onion, cheese, sult...");
	}
}

