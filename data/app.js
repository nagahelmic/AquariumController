async function loadStatus() {
    try {
        const response = await fetch('/api/status');
        const data = await response.json();

        updateAlarmBanner(data.alarm);

        updateTemperature(
            'temperature1',
            'temperature1Status',
            data.waterTemperature1,
            data.alarm,
            1
        );

        updateTemperature(
            'temperature2',
            'temperature2Status',
            data.waterTemperature2,
            data.alarm,
            2
        );

        document.getElementById('wifiStatus').textContent =
            data.wifiConnected ? 'WiFi: connected' : 'WiFi: disconnected';

        document.getElementById('uptime').textContent =
            `Uptime: ${data.uptimeSeconds} s`;
    } catch (error) {
        console.error('Failed to load status:', error);
    }
}

function updateTemperature(valueElementId, statusElementId, reading, alarm, sensorNumber) {
    const valueElement = document.getElementById(valueElementId);
    const statusElement = document.getElementById(statusElementId);

    statusElement.classList.remove('alarm');

    if (!reading.valid) {
        valueElement.textContent = 'ERROR';
        statusElement.textContent = 'Sensor error';
        statusElement.classList.add('alarm');
        return;
    }

    valueElement.textContent = `${reading.valueCelsius.toFixed(1)} °C`;

    const alarmText = getTemperatureAlarmText(alarm, sensorNumber);

    if (alarmText) {
        statusElement.textContent = alarmText;
        statusElement.classList.add('alarm');
    } else {
        statusElement.textContent = 'Sensor OK';
    }
}

function updateAlarmBanner(alarm) {
    const alarmBanner = document.getElementById('alarmBanner');

    if (alarm.active) {
        alarmBanner.classList.remove('hidden');
    } else {
        alarmBanner.classList.add('hidden');
    }
}

function getTemperatureAlarmText(alarm, sensorNumber) {
    if (sensorNumber === 1) {
        if (alarm.waterTemperature1Invalid) {
            return 'Sensor error';
        }

        if (alarm.waterTemperature1Low) {
            return 'Temperature too low';
        }

        if (alarm.waterTemperature1High) {
            return 'Temperature too high';
        }
    }

    if (sensorNumber === 2) {
        if (alarm.waterTemperature2Invalid) {
            return 'Sensor error';
        }

        if (alarm.waterTemperature2Low) {
            return 'Temperature too low';
        }

        if (alarm.waterTemperature2High) {
            return 'Temperature too high';
        }
    }

    return '';
}

loadStatus();
setInterval(loadStatus, 1000);