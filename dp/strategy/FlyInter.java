package dp.strategy;

interface FlyInter {
	void fly();
}

class FlyWithWings implements FlyInter {
	
	void fly() {
		System.out.println("I'm flying with wings");
	}
}

class CannotFly implements FlyInter {

	void fly() {
		System.out.println("I cannot fly!!");
	}
}

