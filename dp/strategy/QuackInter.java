package dp.strategy;
interface QuackInter {
	void Quack();
}

class QuackGa implements QuackInter {
	void Quack() {
		System.out.println("Ga Ga Ga");
	}
}

class CannotQuack implements QuackInter {
	void Quack() {
		System.out.println("I connot quack");
	}
}

