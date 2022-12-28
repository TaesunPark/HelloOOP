//package springboot.learningtest;
//
//import static org.hamcrest.CoreMatchers.*;
//import static org.junit.Assert.assertThat;
//import static org.junit.Assert.assertTrue;
//import static org.junit.matchers.JUnitMatchers.hasItem;
//import org.junit.Test;
//import org.junit.jupiter.api.extension.ExtendWith;
//import org.junit.runner.RunWith;
//import org.springframework.beans.factory.annotation.Autowired;
//import org.springframework.context.ApplicationContext;
//
//import java.util.HashSet;
//import java.util.Set;
//
//
//
//public class JUnitTest {
//    static Set<JUnitTest> testObjects = new HashSet<JUnitTest>();
//    @Autowired
//    ApplicationContext context;
//    static ApplicationContext contextObject = null;
//
//    @Test
//    public void test1(){
//        assertThat(testObjects, not(hasItem(this)));
//        testObjects.add(this);
//        assertThat(contextObject == null || contextObject == this.context, is(true));
//        contextObject = this.context;
//    }
//
//    @Test
//    public void test2(){
//        assertThat(testObjects, not(hasItem(this)));
//        testObjects.add(this);
//
//        assertTrue(contextObject == null || contextObject == this.context);
//        contextObject = this.context;
//    }
//
//    @Test
//    public void test3(){
//        assertThat(testObjects, not(hasItem(this)));
//        testObjects.add(this);
//
//        assertThat(contextObject, either(is(nullValue())).or(is(this.context)));
//        contextObject = this.context;
//    }
//}
