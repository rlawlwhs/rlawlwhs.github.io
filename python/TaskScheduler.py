import subprocess
import os
import win32com.client
import pythoncom
import time
import subprocess


class TaskScheduler():
    SCHEDULER = None

    def __init__(self):
        self.SCHEDULER = win32com.client.Dispatch('Schedule.Service')
        self.SCHEDULER.Connect()

    def create_task(self, InTaskName, InTaskDesc, InPath, InArguments, InTriggerTime, InAuthor="Anonymous"):
        root_folder = self.SCHEDULER.GetFolder('\\')

        taskDef = self.SCHEDULER.NewTask(0)
        taskDef.RegistrationInfo.Description = InTaskDesc
        taskDef.RegistrationInfo.Author = InAuthor

        trigger = taskDef.Triggers.Create(1)
        trigger.StartBoundary = InTriggerTime

        action = taskDef.Actions.Create(0)
        action.Path = InPath
        action.Arguments = InArguments

        taskDef.Settings.Enabled = True
        taskDef.Settings.StartWhenAvailable = False
        taskDef.Settings.Hidden = False

        root_folder.RegisterTaskDefinition(
            InTaskName,                    
            taskDef,                       
            6,                           
            None, None, 3,
        )

    def delete_task(self, InTaskName):
        rootFolder = self.SCHEDULER.GetFolder('\\')

        try:
            task = rootFolder.GetTask(InTaskName)
            task.Enabled = False
            rootFolder.DeleteTask(InTaskName, 0)
        except Exception as e:
            pass


