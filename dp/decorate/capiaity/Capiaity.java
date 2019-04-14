package dp.decorate.capiaity;
import dp.decorate.beverage.*;

public abstract class Capiaity extends Beverage {
	private Beverage beverage;
	private float cupSize = 1;

	Capiaity(Beverage b) {
		this.beverage = b;
	}
	Capiaity(Beverage b, int cupSizeIn) {
		this.beverage = b;
		this.cupSize = cupSizeIn;
	}

	abstract String getDescription();

	int cost() {
		return(beverage.cost()*this.cupSize);
	}
}

class LittleCap extends Capiaity {
	String getDescription() {
		return(beverage.getDescription()+", little cap");
	}
}

class MiddleCap extends Capiaity {
	String getDescription() {
		return(beverage.getDescription()+", middle cap");
	}
}

class BigCap extends Capiaity {
	String getDescription() {
		return(beverage.getDescription()+", big cap");
	}
}



