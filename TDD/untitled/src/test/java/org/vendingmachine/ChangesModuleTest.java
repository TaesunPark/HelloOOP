package org.vendingmachine;

import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.ValueSource;

// Red(질문) -> Green(응답) -> Refactor(정제)

class ChangesModuleTest {

    @Test
    void 자판기_생성(){
        ChangesModule vendingMachine = new ChangesModule();
        Assertions.assertThat(vendingMachine).isNotNull();
    }

    @ParameterizedTest(name = "자판기에 {0}원을 넣으면 {0}원이 들어있음을 알 수 있다")
    @ValueSource(ints = {500, 1000})
    void 자판기에_n원을_넣으면_n원이_들어있음을_알_수_있다(int changes){
        ChangesModule vendingMachine = new ChangesModule();
        vendingMachine.put(1000);
        Assertions.assertThat(vendingMachine.getChanges()).isEqualTo(1000);
    }

    @Test
    void _1000원이_들어있는_자판기에_500원을_넣으면_1500원이_들어있음을_알_수_있다(){
        ChangesModule vendingMachine = new ChangesModule(1000);
        vendingMachine.put(500);
        Assertions.assertThat(vendingMachine.getChanges()).isEqualTo(1500);
    }

    @Test
    void _500원이_들어있는_자판기에_500원을_차감하면_0원이_된다(){
        ChangesModule vendingMachine = new ChangesModule(500);
        vendingMachine.withdraw(500);
        Assertions.assertThat(vendingMachine.getChanges()).isEqualTo(0);
    }

    @Test
    void _0원이_들어있는_자판기에_500원을_차감할_수_없다(){
        ChangesModule vendingMachine = new ChangesModule(0);
        Assertions.assertThatIllegalStateException()
                .isThrownBy(() -> vendingMachine.withdraw(500));
    }


}