% Load Excel data into MATLAB
[~, txtData, rawData] = xlsread('G17_IC_Reading.xlsx');  

% Request user input for IC pin count and readings
numPins = input('Please enter the IC pin count: ');
userReadings = input('Enter your readings as a vector: ');

% Create containers for IC attributes
icNames = {};
pinCounts = [];
normalizedData = {};

% Iterate over each row to capture relevant IC details
for rowIndex = 1:size(txtData, 1)
    icName = txtData{rowIndex, 1};
    pinCount = rawData{rowIndex, 2};
    
    % Proceed only if the row contains both an IC name and a numeric pin count
    if ~isempty(icName) && isnumeric(pinCount)
        icNames{end + 1} = icName;
        pinCounts(end + 1) = pinCount;
        
        % Locate and retrieve normalized values 3 rows down, based on pin count
        normalizedDataRow = rowIndex + 3;
        columnEnd = 2 + pinCount;  % Determine column range
        rowData = rawData(normalizedDataRow, 3:columnEnd);
        
        % Filter out empty cells and non-numeric entries
        rowData = rowData(~cellfun('isempty', rowData));  % Remove empty cells
        rowData = rowData(cellfun(@isnumeric, rowData));  % Keep only numeric values
        validData = cell2mat(rowData);  % Convert to numeric array
        
        normalizedData{end + 1} = validData;
    end
end

% Find matching ICs based on user-specified pin count
matchingIndices = find(pinCounts == numPins);

if isempty(matchingIndices)
    fprintf('No ICs found with %d pins.\n', numPins);
else
    % Compare user's readings to each matching IC's normalized data
    closestMatchIndex = -1;
    minimumScore = Inf;
    
    for match = 1:length(matchingIndices)
        currentIdx = matchingIndices(match);
        currentName = icNames{currentIdx};
        referenceData = normalizedData{currentIdx};
        
        % Only compute similarity if lengths match
        if length(userReadings) == length(referenceData)
            diffScore = norm(userReadings - referenceData);
            
            % Update if a closer match is identified
            if diffScore < minimumScore
                minimumScore = diffScore;
                closestMatchIndex = currentIdx;
            end
        end
    end
    
    % Output the IC with the highest similarity
    if closestMatchIndex > 0
        fprintf('The closest matching IC is: %s\n', icNames{closestMatchIndex});
    else
        fprintf('No close match found based on your readings.\n');
    end
end
