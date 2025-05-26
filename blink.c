#define PERIPH_BASE       0x40000000
#define AHBPERIPH_BASE    (PERIPH_BASE + 0x20000)
#define RCC_BASE          (AHBPERIPH_BASE + 0x1000)
#define GPIOC_BASE        (PERIPH_BASE + 0x11000)

#define RCC_APB2ENR       (*(volatile unsigned int*)(RCC_BASE + 0x18))
#define GPIO_CRH          (*(volatile unsigned int*)(GPIOC_BASE + 0x04))
#define GPIOC_ODR         (*(volatile unsigned int*)(GPIOC_BASE + 0x0C))

#define RCC_IOPEN         (1 << 4)
#define LED_PIN           (1 << 13)


void delay(volatile unsigned int t){
  while(t--){
    for(volatile int i = 0; i < 10; i++);
    
  }
}

int main(void){
  RCC_APB2ENR |= RCC_IOPEN;

  GPIO_CRH &= ~(0xF << 20);
  GPIO_CRH |= (0x2 << 20);

  for(int i = 0; i < 10; ++i){
    GPIOC_ODR &= ~LED_PIN;
    delay(1000);
    GPIOC_ODR |= LED_PIN;
    delay(1000);
  }
  return 0;
}
