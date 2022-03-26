package MultiThread;

import java.util.concurrent.*;

public class MultiThread {

    public static void exec() throws InterruptedException {
        ExecutorService pool = Executors.newFixedThreadPool(8);

        int tasks = 16;
        CountDownLatch latch = new CountDownLatch(tasks);

        for (int i = 0; i < tasks; i++) {
            Future<?> future = pool.submit(() -> {
                try {
                    // 태스크 실행
                } finally {
                    latch.countDown();
                }
            });
        }
        if (!latch.await(2, TimeUnit.SECONDS)) {
            // 타임아웃 처리
        }
    }
}
