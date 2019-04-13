package dp.decorate.decorate;
import dp.decorate.*;

public abstract class Condiment extends Beverage {
	private float price = 0;
	private Beverage beverage;

	Condiment(Beverage b) {
		this.beverage = b;
	}
	Condiment(Beverage b, float priceIn) {
		this.beverage = b;
		this.price = priceIn;
	}

	abstract String getDescription();
	float cost() {
		return(super.cost()+this.price);
	}
}

class ZhenZhu extends Condiment {
	String getDescription() {
		return(super.getDescription+", +zhenzhu");
	}
}

class YeGuo extends Condiment{
	String getDescription() {
		return(super.getDescription+", +yeguo");
	}
}

class BuDing extends Condiment {
	String getDescription() {
		return(super.getDescription+", +buding");
	}
}


