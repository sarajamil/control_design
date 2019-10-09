input = inputu.signals.values(:,1);

outputq1 = outputy.signals.values(:,1);
outputq2 = outputy.signals.values(:,2);

xhat1 = xhat.signals.values(:,1);
xhat2 = xhat.signals.values(:,2);
xhat3 = xhat.signals.values(:,3);
xhat4 = xhat.signals.values(:,4);

figure(1)
plot(input);title('input u');
figure(2)
subplot(2,1,1);
plot(outputq1);title('output q1');
subplot(2,1,2);
plot(outputq2);title('output q2');
figure(3)
subplot(4,1,1);
plot(xhat1);title('xhat1');
subplot(4,1,2);
plot(xhat2);title('xhat2');
subplot(4,1,3);
plot(xhat3);title('xhat3');
subplot(4,1,4);
plot(xhat4);title('xhat4');

