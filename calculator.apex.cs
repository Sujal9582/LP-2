public class CalculatorController {
    public Decimal num1 { get; set; }
    public Decimal num2 { get; set; }
    public Decimal result { get; set; }
    public String operation { get; set; }

    public CalculatorController() {
        num1 = 0;
        num2 = 0;
        result = 0;
        operation = 'Add'; // default
    }

    public void calculate() {
    try {
        if (operation == 'Add') {
            result = num1 + num2;
        } else if (operation == 'Subtract') {
            result = num1 - num2;
        } else if (operation == 'Multiply') {
            result = num1 * num2;
        } else if (operation == 'Divide') {
            if (num2 == 0) {
                result = null;
            } else {
                result = num1 / num2;
            }
        }
    } catch (Exception e) {
        result = null;
    }
	}
}