async function loadStatus() {
    try {
        const response = await fetch('/api/status');
        const data = await response.json();

        updateAlarmBanner(data.alarm);

        updateTemperature(
            'waterTemperature',
            'waterTemperatureStatus',
            data.waterTemperature,
            data.alarm,
            'waterTemperature'
        );

        updateTemperature(
            'roomTemperature',
            'roomTemperatureStatus',
            data.roomTemperature
        );

        document.getElementById('wifiStatus').textContent =
            data.wifiConnected ? 'WiFi: connected' : 'WiFi: disconnected';

        document.getElementById('uptime').textContent =
            `Uptime: ${data.uptimeSeconds} s`;
    } catch (error) {
        console.error('Failed to load status:', error);
    }
}

function updateTemperature(valueElementId, statusElementId, reading, alarm = null, alarmPrefix = null) {
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

    const alarmText = alarm && alarmPrefix
        ? getTemperatureAlarmText(alarm, alarmPrefix)
        : '';

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

function getTemperatureAlarmText(alarm, prefix) {
    if (alarm[`${prefix}Invalid`]) {
        return 'Sensor error';
    }

    if (alarm[`${prefix}Low`]) {
        return 'Temperature too low';
    }

    if (alarm[`${prefix}High`]) {
        return 'Temperature too high';
    }

    return '';
}

loadStatus();
setInterval(loadStatus, 1000);
