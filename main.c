#include "stm32g431xx.h"
// =====================================================================================================================
//  delay func
// =====================================================================================================================
void delay(int a)
{
    volatile int i, j;

    for (i = 0; i < a; i++)
    {
        j++;
    }
}

void PB8_toggle(void)
{
    volatile uint32_t state = (GPIOB->ODR & GPIO_ODR_OD8_Msk);
    if (state)
    {
        GPIOB->BSRR |= GPIO_BSRR_BR8;
    }
    else
    {
        GPIOB->BSRR |= GPIO_BSRR_BS8;
    }
}

int main(void)
{
    //SystemCoreClockUpdate();
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;
    GPIOB->MODER |= GPIO_MODER_MODE8_0;
    GPIOB->OTYPER &= ~(GPIO_OTYPER_OT8);
    GPIOB->PUPDR &= ~(GPIO_PUPDR_PUPD8);
    GPIOB->BSRR |= GPIO_BSRR_BS8;

    while (1)
    {
        delay(0xFFF);
        PB8_toggle();
    }
}
