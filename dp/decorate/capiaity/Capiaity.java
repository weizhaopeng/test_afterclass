package dp.decorate.capiaity;
import dp.decorate.beverage;

public abstract class Capiaity extends Beverage {
	private Beverage beverage;
	private int price = 1;

	Capiaity(Beverage b) {
		this.beverage = b;
	}
	Capiaity(Beverage b, int priceIn) {
		this.beverage = b;
		this.price	  = priceIn;
	}

	abstract String getDescription();

	int cost() {
		return(super.cost()*this.price);
	}
}

class LittleCap extends Capiaity {
	String getDescription() {
		return(super.getDescription()+", little cap");
	}
}

class MiddleCap extends Capiaity {
	String getDescription() {
		return(super.getDescription()+", middle cap");
	}
}

class BigCap extends Capiaity {
	String getDescription() {
		return(super.getDescription()+", big cap");
	}
}



