var Car = /** @class */ (function () {
    function Car(speed) {
        this.speed = speed || 0;
    }
    Car.prototype.accelerate = function () {
        this.speed++;
    };
    Car.prototype.getSpeed = function () {
        console.log(this.speed);
    };
    return Car;
}());
var car = new Car(5);
car.accelerate();
car.getSpeed();
