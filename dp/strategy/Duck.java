package dp.strategy;

public class Duck {
	FlyInter fly;
	QuackInter quack;
	boolean  isAlive;

	void flyPerformance() {
		fly.fly();
	}
	void quackPerformance() {
		quack.quack();
	}

	void setFlyBehavior(FlyInter f) {
		fly = f;
	}
	void setQuackBehavior(QuackInter q) {
		quack = q;
	}
}

class YanShuiDuck extends Duck {
	YanShuiDuck() {
		fly = new CannotFly();
		quack = new CannotQuack();
		isAlive = false;
	}
	YanShuiDuck(FlyInter f, QuackInter q, boolean isAliveIn) {
		fly = f;
		quack = q;
		isAlive = isAliveIn;
	}
}

class YellowDuck extends Duck {
	YellowDuck() {
		fly = new FlyWithWings();
		quack = new QuackGa();
		isAlive = true;
	}
}


